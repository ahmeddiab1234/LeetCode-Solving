# https://leetcode.com/problems/nth-highest-salary/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata



import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:
    unique_salaries = employee['salary'].drop_duplicates().sort_values(ascending=False)
    nth_high = unique_salaries.iloc[N-1] if len(unique_salaries) >=N and N >0 else None
    return pd.DataFrame({f'getNthHighestSalary({N})' : [nth_high]})

