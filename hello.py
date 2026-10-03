import pandas as pd
from sklearn.tree import DecisionTreeRegressor
from sklearn.ensemble import RandomForestRegressor
from sklearn.metrics import mean_absolute_error
from sklearn.model_selection import train_test_split

homedata=pd.read_csv('homedataset.csv')
X=homedata[['LotArea', 'YearBuilt', '1stFlrSF', '2ndFlrSF', 'FullBath', 'BedroomAbvGr', 'TotRmsAbvGrd']]
y=homedata['SalePrice']

trainX, valX, trainy, valy = train_test_split(X, y, random_state=1)

model = RandomForestRegressor(random_state=1)
model.fit(trainX, trainy)
predictions = model.predict(valX)
mae = mean_absolute_error(valy, predictions)

print("MAE:",mae)