# https://leetcode.com/problems/students-and-examinations/description/?envType=study-plan-v2&envId=30-days-of-pandas&lang=pythondata


import pandas as pd

def students_and_examinations(students: pd.DataFrame, subjects: pd.DataFrame, examinations: pd.DataFrame) -> pd.DataFrame:
    all_combinations = students.assign(key=1).merge(subjects.assign(key=1), on='key').drop(columns=['key'])
    
    exam_counts = examinations.groupby(['student_id', 'subject_name']).size().fillna(0).reset_index(name='attended_exams')

    result = all_combinations.merge(exam_counts, on=['student_id', 'subject_name'], how='left')
    result['attended_exams'] = result['attended_exams'].fillna(0).astype(int)
    result = result.sort_values(by=['student_id', 'subject_name'])

    return result[['student_id', 'student_name', 'subject_name', 'attended_exams']]




