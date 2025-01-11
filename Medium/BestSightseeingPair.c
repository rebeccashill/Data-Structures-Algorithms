/*
    You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
    The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
    Return the maximum score of a pair of sightseeing spots.
*/

int maxScoreSightseeingPair(int* values, int valuesSize) {
    int max = 0, max_i = values[0], max_score=0;
    for (int j=1;j<valuesSize;j++)
    {
        max_score = fmax(max_score, max_i + values[j]-j);
        max_i = fmax(max_i, values[j]+j);
    }
    return max_score;
}