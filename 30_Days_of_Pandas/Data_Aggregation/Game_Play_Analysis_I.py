#  https://leetcode.com/problems/game-play-analysis-i/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def game_analysis(activity: pd.DataFrame) -> pd.DataFrame:
    result = activity.groupby('player_id', as_index=False)['event_date'].min()
    return result.rename(columns={'event_date':'first_login'})



