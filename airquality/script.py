
import pandas as pd
import numpy as np

from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import OneHotEncoder
from sklearn.impute import SimpleImputer
from sklearn.pipeline import Pipeline
from sklearn.ensemble import RandomForestRegressor

train = pd.read_csv("train.csv")
test = pd.read_csv("test.csv")

train = train.dropna(subset=["AQI"])
test_index = test["Index"]

def preprocess_features(df):
    df = df.copy()

    time = pd.to_datetime(
        df["Time"],
        format="%I:%M %p",
        errors="coerce"
    )

    df["Time"] = time.dt.hour * 60 + time.dt.minute

    month_mapping = {
        "January": 1, "February": 2,
        "March": 3, "April": 4,
        "May": 5, "June": 6,
        "July": 7, "August": 8,
        "September": 9, "October": 10,
        "November": 11, "December": 12
    }

    df["Month"] = df["Month"].str.strip().str.title()
    df["Month"] = df["Month"].map(month_mapping)

    weekday_mapping = {
        "Monday": 1, "Tuesday": 2,
        "Wednesday": 3, "Thursday": 4,
        "Friday": 5, "Saturday": 6,
        "Sunday": 7
    }

    df["Day_of_Week"] = (
        df["Day_of_Week"].str.strip().str.title()
    )

    df["Day_of_Week"] = df["Day_of_Week"].map(
        weekday_mapping
    )

    quarter_mapping = {
        "Q1": 1,
        "Q2": 2,
        "Q3": 3,
        "Q4": 4
    }

    df["Month_Quarter"] = (
        df["Month_Quarter"].str.strip().str.upper()
    )

    df["Month_Quarter"] = df["Month_Quarter"].map(
        quarter_mapping
    )

    df["Day_Type"] = df["Day_Type"].str.strip().str.title()

    df = df.drop(
        columns=[
            "Index",
            "City",
            "Date",
            "Day_Phase",
            "AQI_Bucket",
            "AQI"
        ],
        errors="ignore"
    )

    return df


X_train = preprocess_features(train)
X_test = preprocess_features(test)

y_train = train["AQI"]

day_type_categories = set(
    pd.concat([
        X_train["Day_Type"],
        X_test["Day_Type"]
    ]).dropna().unique()
)

if day_type_categories.issubset({"Weekday", "Weekend"}):
    mapping = {
        "Weekday": 1,
        "Weekend": 0
    }

    X_train["Day_Type"] = X_train["Day_Type"].map(mapping)
    X_test["Day_Type"] = X_test["Day_Type"].map(mapping)

    categorical_features = ["Season", "location"]

else:
    categorical_features = [
        "Season", "location", "Day_Type"
    ]

numerical_features = X_train.select_dtypes(
    include=["number"]
).columns.tolist()

numerical_features = [
    col for col in numerical_features
    if col not in categorical_features
]

numerical_pipeline = Pipeline(steps=[
    ("imputer", SimpleImputer(strategy="median"))
])

categorical_pipeline = Pipeline(steps=[
    ("imputer", SimpleImputer(strategy="most_frequent")),
    ("encoder", OneHotEncoder(handle_unknown="ignore"))
])

preprocessor = ColumnTransformer(
    transformers=[
        ("num", numerical_pipeline, numerical_features),
        ("cat", categorical_pipeline, categorical_features)
    ]
)

model = Pipeline(steps=[
    ("preprocessor", preprocessor),
    ("regressor", RandomForestRegressor(
        n_estimators=300,
        random_state=42,
        n_jobs=-1
    ))
])

model.fit(X_train, y_train)

predictions = model.predict(X_test)

submission = pd.DataFrame({
    "Index": test_index,
    "AQI": predictions
})

submission.to_csv("submission.csv", index=False)

print("Submission generated successfully!")
print(submission.head())
print("Shape:", submission.shape)
print(submission.isna().sum())
print(submission["AQI"].describe())
