# https://leetcode.com/problems/article-views-i/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    new_df = views[views['author_id'] == views['viewer_id']]
    new_df = new_df[['author_id']].drop_duplicates()
    new_df = new_df.sort_values(by='author_id', ascending=True)
    return new_df.rename(columns={'author_id': 'id'})



