#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Applicant {
    int document_score;
    int interview_score;
};

bool compareByDocumentScore(const Applicant &a, const Applicant &b) {
    return a.document_score < b.document_score;
}

void hireApplicants(const std::vector<Applicant> &applicants) {
    int hired = 1;
    int minInterviewScore = applicants[0].interview_score;

    for (int i = 1; i < applicants.size(); ++i) {
        if (applicants[i].interview_score < minInterviewScore) {
            minInterviewScore = applicants[i].interview_score;
            hired++;
        }
    }

    cout << hired << "\n";
}

int main() {
    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n;
        cin >> n;

        vector<Applicant> applicants(n);
        for (int i = 0; i < n; ++i) {
            cin >> applicants[i].document_score >> applicants[i].interview_score;
        }

        sort(applicants.begin(), applicants.end(), compareByDocumentScore);

        hireApplicants(applicants);
    }

    return 0;
}
