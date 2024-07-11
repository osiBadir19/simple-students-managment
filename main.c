// create program that allows a teacher to track and manage student grades for a course.
// the program should provide the following functionaliites: 
// 1) adding new students
// 2) entering grades for assignments/exams
// 3) calculating statstics (average, highest, lowest)
// 4) displaying individual student records


#include <stdio.h>
#define true 1
#define false 0
#define MAX_LENGTH 1000

// identify global variables
int students_ids[MAX_LENGTH];
int math_grades[MAX_LENGTH];
int english_grades[MAX_LENGTH];
int physics_grades[MAX_LENGTH];


// functions decalrations
int checkIfStudentExists(int student_id);
int empty_index(int a[]);
int find_index(int a[], int value);
void setValue(int a[], int value, int student_id);
float average();
int calcaulteMax(int classNum);
void maxStudent();
int calcaulteMax(int classNum);
void maxStudent();
void add_student();
void add_grades();
void printData();
void stats();


int main() {
    int flag = true;
    int choice;

    printf("Welcome to portal.\n");
    while (flag != false) {
        printf("These are options (-1 to exit):\n");
        printf("1) Add students\n");
        printf("2) Add grades\n");
        printf("3) Statistics\n");
        printf("4) Display data per student\n");
        scanf("%d", &choice);

        // Clear input buffer after reading an integer
        while (getchar() != '\n');

        switch (choice) {
            case -1:
                flag = false;
                break;
            case 1:
                add_student();
                break;
            case 2:
                add_grades();
                break;
            case 3:{
                stats();
                break;
            }
            case 4:
                printData();
                break;
            default:
                printf("ERROR: Please choose 1, 2, 3, 4, or -1 to exit\n");
                break;
        }
    }

    printf("Exiting program.\n");
    return 0;
}


/// @brief check if student exists in database
/// @return 0 if no match; 1 if there is a match
int checkIfStudentExists(int student_id){
    for (int i = 0; i < MAX_LENGTH; i++){
        if (students_ids[i] == student_id)
            return 1;
    }
    return 0;       // no match
}


/// @brief check the empty index
/// @param a the array you want to check
/// @return the index in case there is an empty spot; -1 if there is none
int empty_index(int a[]){
    for (int i = 0; i < MAX_LENGTH; i++){
        if (a[i] == '\0')
            return i;
    }
    return -1;
}



/// @brief check the index of a given value
/// @param a the array we want to check
/// @param value the value we want to check it in the array
/// @return the index of the array
int find_index(int a[], int value){
    for (int i = 0; i < MAX_LENGTH; i++){
        if(a[i] == value)
            return i;
    }

    // if no match, return -1
    return -1;
}


/// @brief set a value in a array with value
/// @param a the array to modify
/// @param value the value we want to add
/// @param student_id the student_id so we can find his index (student_id is primary key here)
void setValue(int a[], int value, int student_id){
    int index = find_index(students_ids, student_id);

    if (index != -1)
        a[index] = value;
}



/// @brief calcaulute the average of grades for a student
/// @param student_id id of student we want to check
/// @return the average of grades
float average(){
    int sum = 0;
    int student_id;
    printf("enter student id: ");
    scanf("%d", &student_id);

    int index;
    index = find_index(students_ids, student_id);
    sum += math_grades[index] + english_grades[index] + physics_grades[index];

    return (sum / 3);
}


/// @brief find the index of the grade with max value (to match with student id)
/// @param classNum the class we want to check
/// @return the index of the grade
int calcaulteMax(int classNum){
    int max = -1;
    int index;
    if (classNum == 1){
        for (int i = 0; i < MAX_LENGTH; i++){
            if (math_grades[i] > max){
                max = math_grades[i];
                index = i;
            }
            
        }
    }
    else if (classNum == 2){
        for (int i = 0; i < MAX_LENGTH; i++){
            if (english_grades[i] > max){
                max = english_grades[i];
                index = i;
            }
        }
    }
    else if (classNum == 3){
        for (int i = 0; i < MAX_LENGTH; i++){
            if (physics_grades[i] > max){
                max = physics_grades[i];
                index = i;
            }
        }
    }
    return index;
}

/// @brief print the student_id with maximum grade in a given class
void maxStudent(){
    int classNum;
    int flag = true;

    while (flag != false){
        printf("please enter:  1) math\t2) english\t3) physics\n");
        scanf("%d", &classNum);

    if ((classNum != 1) && (classNum != 2) && (classNum != 3))
        printf("ERROR: enter either 1, 2, or 3\n");
    else{
        printf("the student id with max grade is: %d\n", students_ids[calcaulteMax(classNum)]);
        flag = false;
    }
    }
}



/// @brief find the index of the grade with min value (to match with student id)
/// @param classNum the class we want to check
/// @return the index of the grade
int calcaulteMin(int classNum){
    int min;
    int index;
    if (classNum == 1){
        for (int i = 0; i < MAX_LENGTH; i++){
            if (math_grades[i] < min){
                min = math_grades[i];
                index = i;
            }
            
        }
    }
    else if (classNum == 2){
        for (int i = 0; i < MAX_LENGTH; i++){
            if (english_grades[i] < min){
                min = english_grades[i];
                index = i;
            }
        }
    }
    else if (classNum == 3){
        for (int i = 0; i < MAX_LENGTH; i++){
            if (physics_grades[i] < min){
                min = physics_grades[i];
                index = i;
            }
        }
    }
    return index;
}


/// @brief print the student_id with minimum grade in a given class
void minStudent(){
    int classNum;
    int flag = true;

    while (flag != false){
        printf("please enter:  1) math\t2) english\t3) physics\n");
        scanf("%d", &classNum);

    if ((classNum != 1) && (classNum != 2) && (classNum != 3))
        printf("ERROR: enter either 1, 2, or 3\n");
    else{
        printf("the student id with min grade is: %d\n", students_ids[calcaulteMin(classNum)]);
        flag = false;
    }
    }
}


/// @brief add a student to the students database
void add_student(){
    int student_id, index;
    int flag = true;

    while (flag != false){
        printf("Enter student ID (-1 to exit): ");
        scanf("%d", &student_id);
        if (student_id == -1){
            printf("Stopping student ID input.\n");
            flag = false;
            break;
        }

        index = empty_index(students_ids);
        if (index != -1){
            students_ids[index] = student_id;
        }
        else {
            printf("ERROR: Array out of index.\n");
            break;
        }
    }
}



/// @brief add a grade to grades database for a student
void add_grades(){
    int grade, student_id, index, input;
    int flag = true;
    int inner_flag = true;

    printf("Welcome to grades portal\n");

    while (flag != false){
        printf("Please enter student id (-1 to exit): ");
        scanf("%d", &student_id);

        if (student_id == -1)
            flag = false;
        
        else if (checkIfStudentExists(student_id) == 1){
            while (inner_flag != false){
                printf("choose subject (-1 to exit):\n1) math\n2) english\n3) physics\n");
                scanf("%d", &input);

                if (input == -1)
                    inner_flag = false;

                else{
                    printf("enter grade: ");
                    scanf("%d", &grade);
                    switch (input){
                        case 1:
                            setValue(math_grades, grade, student_id);
                            break;
                        case 2:
                            setValue(english_grades, grade, student_id);
                            break;
                        case 3:
                            setValue(physics_grades, grade, student_id);
                            break;
                        default:
                            printf("ERROR: Choose either 1, 2, 3 or -1 to exit.\n");
                            break;
                    }

                }

            }
        }
        // if student doesn't exist: 
        else
            printf("student id doesn't exist.\n");


        inner_flag = true;      // Reset inner flag for next student
        
    }
}


/// @brief print the grades data of a student in a formatted way
void printData(){
    int student_id;
    printf("enter student id: ");
    scanf("%d", &student_id);

    int student_index = find_index(students_ids, student_id);
    if (student_index == -1){
        printf("Student ID %d not found.\n", student_id);
        return;
    }


    int math = math_grades[student_index];
    int english = english_grades[student_index];
    int physics = physics_grades[student_index];

    printf("- - - - - - - - - - - - - - - - - - - - -\n");
    printf("- student id: %10d              -\n", student_id);
    printf("- - - - - - - - - - - - - - - - - - - - -\n");
    printf("-    math   -   english  -   physics    -\n");
    printf("-   %3d - - -   %3d - - -  %3d  - -\n", math, english, physics);
    printf("- - - - - - - - - - - - - - - - - - - - -\n");

}


/// @brief show statstics options
void stats(){
    int choice;
    printf("1) average, 2) maximum student, 3) minimum student: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        average();
        break;
    
    case 2:
        maxStudent();
        break;
    
    case 3:
        minStudent();
        break;

    default:
        printf("ERROR: invalid choice");
        break;
    }
}






