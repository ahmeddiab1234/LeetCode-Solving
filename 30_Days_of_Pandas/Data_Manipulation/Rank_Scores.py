# https://leetcode.com/problems/rank-scores/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def order_scores(scores: pd.DataFrame) -> pd.DataFrame:
    scores.sort_values(by='score', ascending=False, inplace=True)
    scores['rank'] = scores['score'].rank(method='dense', ascending=False).astype(int)
    return scores[['score', 'rank']]




