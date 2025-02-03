# https://leetcode.com/problems/managers-with-at-least-5-direct-reports/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata

import pandas as pd

def find_managers(employee: pd.DataFrame) -> pd.DataFrame:
    manager_counts = employee.groupby('managerId')['id'].count().reset_index(name='sz')
    manager_counts = manager_counts[manager_counts['sz'] >= 5]
    manager_counts = manager_counts.merge(employee[['id', 'name']], left_on='managerId', right_on='id', how='inner')
    return manager_counts[['name']]



