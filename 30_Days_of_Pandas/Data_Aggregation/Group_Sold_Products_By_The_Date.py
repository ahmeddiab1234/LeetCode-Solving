# https://leetcode.com/problems/group-sold-products-by-the-date/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def categorize_products(activities: pd.DataFrame) -> pd.DataFrame:
    df_new = activities.groupby('sell_date')['product']\
        .apply(lambda x: ','.join(sorted(set(x)))).reset_index()
    df_new['num_sold'] = df_new['product'].apply(lambda x: len(x.split(',')) )

    return df_new[['sell_date', 'num_sold', 'product']].rename(columns={'product':'products'})




