#include <stdio.h>
#include "grade_card.h"

int main() {
    // Create and fill a GradeCard
    GradeCard gradeCard;
    fillGradeCard(&gradeCard);

    // Print the GradeCard details
    printf("Before modification:\n");
    printGradeCard(&gradeCard);

    // Modify or manipulate the GradeCard as needed

    // Free the GradeCard memory
    freeGradeCard(&gradeCard);

    return 0;
}
