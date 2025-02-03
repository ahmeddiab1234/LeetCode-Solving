# https://leetcode.com/problems/accepted-candidates-from-the-interviews/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd


def accepted_candidates(candidates: pd.DataFrame, rounds: pd.DataFrame) -> pd.DataFrame:
    rounds_sum = rounds.groupby('interview_id', as_index=False)['score'].sum()
    passed_interviews = rounds_sum[rounds_sum['score'] >= 15][['interview_id']]
    
    eligible_candidates = candidates[candidates['years_of_exp'] >= 2]
    
    result = eligible_candidates.merge(passed_interviews, on='interview_id', how='inner')
    
    return result[['candidate_id']]

