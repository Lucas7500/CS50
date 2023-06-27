#include <stdio.h>
#include <string.h>

typedef char *string;

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
int vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count;

    printf("Number of voters: ");
    scanf("%d", &voter_count);

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name;
        printf("Vote: ");
        scanf("%[^\n]%*c", name);

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
int vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            return 1;
        }
    }

    return 0;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int i, j;
    string most_voted;
    string temp_name;

    // Organize candidates in descending order by the number of votes
    for (i = 0; i < candidate_count; i++)
    {
        for (j = i + 1; j < candidate_count; j++)
        {
            if (candidates[i].votes > most_voted)
            {
                most_voted = candidates[i].name;
            }
        }
    }

    printf("%s\n", most_voted);

    // Checks if there is a tie and if so, shows the other winners
    for (i = 1; i < candidate_count; i++)
    {
        if (most_voted == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}