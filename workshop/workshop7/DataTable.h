#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H

#include <fstream>
#include <functional>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iomanip>
#include <cmath>

namespace w7 {
    template<typename T>
    class DataTable{
        std::vector<T> m_xData;
        std::vector<T> m_yData;
        int m_fWidth = 0;
        int m_numDecimals = 0;
    public:
        DataTable(){}
        DataTable(std::ifstream& file, int fWidth, int numDecimals): m_fWidth{fWidth}, m_numDecimals{numDecimals}{
            T x, y;
            while(file >> x && file >> y){
                m_xData.push_back(x);
                m_yData.push_back(y);
            }
        }
        
        T mean() const{
            return std::accumulate(m_yData.begin(), m_yData.end(), (T)(0)) / m_yData.size();
        }
        
        T sigma() const{
            T yMean = mean();
            std::vector<T> temp(getSize());
            std::transform(m_yData.begin(), m_yData.end(), temp.begin(), [yMean](T y) {return y - yMean;});
            T productSum = std::inner_product(temp.begin(), temp.end(), temp.begin(), (T)0);
            
            return std::sqrt(productSum / (m_yData.size() - 1));
        }
        
        T median() const{
            std::vector<T> temp(m_yData.size());
            std::copy(m_yData.begin(), m_yData.end(), temp.begin());
            std::sort(temp.begin(), temp.end());
            
            return temp[m_yData.size() / 2];
        }
        
        void regression(T& slope, T& y_intercept) const{
            T sum_x = accumulate(m_xData.begin(), m_xData.end(), (T)0);
            T sum_y = accumulate(m_yData.begin(), m_yData.end(), (T)0);
            T productSum_xx = std::inner_product(m_xData.begin(), m_xData.end(), m_xData.begin(), (T)0);
            T productSum_xy = std::inner_product(m_xData.begin(), m_xData.end(), m_yData.begin(), (T)0);
            slope = (getSize() * productSum_xy - sum_x * sum_y) / (getSize() * productSum_xx - sum_x * sum_x);
            y_intercept = (sum_y - slope * sum_x) / getSize();
        }
        
        void display(std::ostream& os) const{
            os << std::fixed << std::setprecision(m_numDecimals);
            os << std::setw(m_fWidth) << 'x' << std::setw(m_fWidth) << 'y' << std::endl;
            for(auto i = 0; i < getSize(); ++i){
                os << std::setw(m_fWidth) << m_xData[i] << std::setw(m_fWidth) << m_yData[i] << std::endl;
            }
            os.unsetf(std::ios_base::fixed);
            os << std::setprecision(6);
        }
        
        size_t getSize() const{
            return m_xData.size();
        }
    };
    
    template <typename T>
    std::ostream& operator<<(std::ostream& os, const DataTable<T>& datatable){
        datatable.display(os);
        return os;
    }
}
#endif
