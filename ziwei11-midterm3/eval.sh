#!/bin/bash
QUESTIONS="question1 question2 question3 question4"
for question in ${QUESTIONS}
do
    echo $question
    (make lint-${question}.c $* && echo \"${question}-lint\":1,) || echo \"${question}-lint\":0,
    (make run-${question} $* && echo \"${question}\":1,) || echo \"${question}\":0,
done
