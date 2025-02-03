# https://leetcode.com/problems/sales-person/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def sales_person(sales_person: pd.DataFrame, company: pd.DataFrame, orders: pd.DataFrame) -> pd.DataFrame:
    red_com = company[company['name']=='RED']
    red_order = orders[orders['com_id'].isin(red_com['com_id'])]
    sales_red_order = red_order['sales_id'].unique()

    sales_not_order = sales_person[~sales_person['sales_id'].isin(sales_red_order)]
    return sales_not_order[['name']]




