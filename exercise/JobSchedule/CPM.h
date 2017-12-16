#include<fstream>
#include<vector>

class CPM
{
public:
    explicit CPM();
    ~CPM();

    void Parse(std::ifstream& inf);
    double distTo(int v);
private:
    std::vector<double> distto_;
};