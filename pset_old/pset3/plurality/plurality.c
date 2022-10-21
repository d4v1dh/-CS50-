
/*
 *                                                  _____________ ___ 
 *   plurality.c                                   / ___/ __/ __// _ \
 *                                                / /___\ \/__ \/ // /
 *   By: dhalley <dhalley@null.net>               \___/___/____/\___/ 
 *
 */

#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
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

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    int i = 0;
    while (i < voter_count)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
        else
        {
            i++;
        }

    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    int x;

    x = 0;
    while (x < candidate_count)
    {
        if (strcmp(name, candidates[x].name) == 0)
        {
            candidates[x].votes++;
            return true;
        }
        else
        {
            x++;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int max;
    int x;
    int y;

    max = 0;
    x = 0;
    while (x < candidate_count)
    {
        if (max < candidates[x].votes)
        {
            max = candidates[x].votes;
        }
        x++;
    }
    y = 0;
    while (y < candidate_count)
    {
        if (candidates[y].votes == max)
        {
            printf("%s\n", candidates[y].name);
        }
        y++;
    }

    return;
}

