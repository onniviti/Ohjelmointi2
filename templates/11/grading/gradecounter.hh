#ifndef GRADECOUNTER_HH
#define GRADECOUNTER_HH

// Before passing automated tests, do not touch the constant values below,
// even if they differ from those you see in Plussa.
// At the end of the course, if you use this program to count your final grade,
// check the values and update them identical with those in Plussa, if needed.
const unsigned int MAX_N_POINTS = 760;
const unsigned int MAX_G_POINTS = 120;
const unsigned int MAX_P_POINTS = 250;

// Counts the final grade by calling the other functions below.
unsigned int count_final_grade(unsigned int n, unsigned int g,
                               unsigned int p, unsigned int e);

// Counts score from weekly exercises.
unsigned int score_from_weekly_exercises(unsigned int n, unsigned int g);

// Counts score from GUI exercises.
unsigned int score_from_gui_exercises(unsigned int g);

// Counts score from projects.
unsigned int score_from_projects(unsigned int p);

// Compares the mean value counted based on scores from weekly exercises and
// projects, and possibly also from the exam, with score from GUI exercises.
// If score from GUI exercises is good enough, returns mean as the final grade,
// otherwise returns score from GUI exercises as the final grade.
unsigned int compare_mean_and_gui_score(float mean, unsigned int g);

#endif // GRADECOUNTER_HH

