# https://leetcode.com/problems/second-highest-salary/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    unique_salaries = employee['salary'].drop_duplicates().sort_values(ascending=False)
    scnd_high = unique_salaries.iloc[1] if len(unique_salaries) >=2 else None
    return pd.DataFrame({f'SecondHighestSalary' : [scnd_high]})




