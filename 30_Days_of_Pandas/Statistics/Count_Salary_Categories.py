# https://leetcode.com/problems/count-salary-categories/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    low_sal = (accounts['income'] < 20000).sum()
    avg_sal = ((accounts['income'] >= 20000) & (accounts['income'] <= 50000)).sum()
    high_sal = (accounts['income'] > 50000).sum()
    return pd.DataFrame({'category': ['Low Salary', 'Average Salary', 'High Salary'], 'accounts_count': [low_sal, avg_sal, high_sal]})




