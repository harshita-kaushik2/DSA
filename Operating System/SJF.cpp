#include <algorithm>

bool comp (const vector<int> &process1, const vector<int> &process2) {
    if (process1[1] != process2[1]) 
		return process1[1] < process2[1];
	else if (process1[2] != process2[2]) 
		return process1[2] < process2[2];
	else 
		return process1[0] < process2[0];
}

vector<vector<int>> shortestJobFirst(int n, vector<int> &processId, vector<int> &arrivalTime, vector<int> &burstTime) {
    vector<vector<int>> processDetails(n, vector<int>(6));
    for (int i = 0; i < n; i++) {
        processDetails[i][0] = processId[i];
        processDetails[i][1] = arrivalTime[i];
        processDetails[i][2] = burstTime[i];
    }

    sort(processDetails.begin(), processDetails.end(), comp);

    processDetails[0][3] = processDetails[0][1] + processDetails[0][2];
    processDetails[0][5] = processDetails[0][3] - processDetails[0][1];
    processDetails[0][4] = processDetails[0][5] - processDetails[0][2];

    for (int i = 1; i < n; i++) {
        int prevCompTime = processDetails[i - 1][3];
        int currBurstTime = processDetails[i][2];
        int currId = processDetails[i][0];
        int index = i;

        for (int j = i; j < n; j++) {
            if (processDetails[j][1] <= prevCompTime) {
                if (processDetails[j][2] < currBurstTime) {
                    currBurstTime = processDetails[j][2];
                    currId = processDetails[j][0];
                    index = j;
                }
                else if (processDetails[j][2] == currBurstTime && processDetails[j][0] < currId) {
                    currId = processDetails[j][0];
                    index = j;
                }
            }
        }
        processDetails[index][3] = prevCompTime + processDetails[index][2];

        processDetails[index][5] = max(processDetails[index][3] - processDetails[index][1], 0);
        processDetails[index][4] = max(processDetails[index][5] - processDetails[index][2], 0);
        swap(processDetails[index], processDetails[i]);
    }

    vector<vector<int>> answer(n, vector<int>(5));

    for (int i = 0; i < n; i++) {
        int index = 0;
        for (int j = 0; j < 6; j++) {
            if (j != 3) {
                answer[i][index] = processDetails[i][j];
                index++;
            }
        }
    }
    return answer;
}
