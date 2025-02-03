# https://leetcode.com/problems/department-highest-salary/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def department_highest_salary(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    merged = employee.merge(department, left_on='departmentId', right_on='id')
    max_salary_per_dept = merged.groupby('departmentId')['salary'].max().reset_index()
    result = merged.merge(max_salary_per_dept, on=['departmentId', 'salary'])

    return result[['name_y', 'name_x', 'salary']].rename(columns={'name_y': 'Department', 'name_x': 'Employee'})

