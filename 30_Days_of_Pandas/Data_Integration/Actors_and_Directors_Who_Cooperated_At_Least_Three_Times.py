# https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def actors_and_directors(actor_director: pd.DataFrame) -> pd.DataFrame:
    df_new = actor_director.groupby(['actor_id', 'director_id']).size().reset_index(name='count')
    df_new = df_new[df_new['count'] >=3]
    return df_new[['actor_id', 'director_id']]



