SELECT
    st.student_id AS student_id,
    st.student_name AS student_name,
    sj.subject_name AS subject_name,
    COUNT(e.student_id) AS attended_exams
FROM
    Students AS st
CROSS JOIN
    Subjects AS sj
LEFT JOIN
    Examinations AS e ON st.student_id = e.student_id AND sj.subject_name = e.subject_name
GROUP BY
    st.student_id,
    sj.subject_name
ORDER BY
    st.student_id, sj.subject_name;