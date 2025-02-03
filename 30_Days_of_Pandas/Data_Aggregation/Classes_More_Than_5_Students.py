#   https://leetcode.com/problems/classes-more-than-5-students/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def find_classes(courses: pd.DataFrame) -> pd.DataFrame:
    result = courses.groupby('class')['student'].count().reset_index()
    result = result[result['student'] >= 5]
    return result[['class']]


