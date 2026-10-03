import pandas as pd
import numpy as np
import cv2 as cv

data = {
    'Name': ['Zaid', 'Tanush', 'Shounak', 'Shreya', 'Aman'],
    'Age': [19, 19, np.nan, 19, 21],
    'Marks': [85, np.nan, 78, 92, 65],
    'Branch': ['CSE', 'CSE', 'IT', 'ECE', 'CSE']
}

df = pd.DataFrame(data)

print(df)

