#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int rank = 0; rank < candidate_count; rank++)
    {
        for (int column = rank + 1; column < candidate_count; column++)
        {
            preferences[ranks[rank]][ranks[column]] ++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
//checking to see who has more votes
            if (preferences[i][j] > preferences[j][i])
            {
//create a new pair and updating it
                pair new_Pair = {i, j};
                pairs[pair_count] = new_Pair;
                pair_count++;
            }
        }
    }
    return;
}
int pair_mass(i)
{
    int pair_winner = pairs[i].winner;
    int pair_loser = pairs[i].loser;
    return preferences[pair_winner][pair_loser];
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
//choosing selection sort.... find the smallest and then swap with the first of the unsorted list

    for (int i = pair_count - 1; i >= 0; i--)
    {
        int smallest_mass = pair_mass(i);
        int smallest_index = i;

        for (int j = i - 1; j >= 0; j--)
        {
            if (pair_mass(j) < smallest_mass)
            {
                smallest_mass = pair_mass(j);
                smallest_index = j;
            }
        }
    }
//swapping with the heaviest index
    pair store = pairs[smallest_index];
//swapping
    pairs[smallest_index] = pairs[i];
    pairs[i] = store;
    return;
}

//create a function to check if their is no cycle
bool cycle(int winner, int loser)
{
    if (locked[loser][winner] == true)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser] == true && cycle(winner, i))
        {
            return true;
        }
    }
    return false;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;
        if (!cyle(winner, loser))
        {
            locked[winner][loser] = true
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (row = 0; row < candidate_count; row++)
    {
        for (int column = 0; column < candidate_count; column++)
        {
            if (locked[row][column] == true)
            {
                break;
            }
        }
        else if (column == candidate - 1)
        {
            printf("%s", candidates[row]);
        }
    }
    return;
}