#include "HeatIndexDisplay.h"

double HeatIndexDisplay::computeHeatIndex(double ct, double rh) 
{
    auto t = (9.0 / 5.0) * ct + 32.0;
    double index = (double)((16.923 + (0.185212 * t) + (5.37941 * rh) - (0.100254 * t * rh) 
        + (0.00941695 * (t * t)) + (0.00728898 * (rh * rh)) 
        + (0.000345372 * (t * t * rh)) - (0.000814971 * (t * rh * rh)) +
        (0.0000102102 * (t * t * rh * rh)) - (0.000038646 * (t * t * t)) + (0.0000291583 * 
        (rh * rh * rh)) + (0.00000142721 * (t * t * t * rh)) + 
        (0.000000197483 * (t * rh * rh * rh)) - (0.0000000218429 * (t * t * t * rh * rh)) +
        0.000000000843296 * (t * t * rh * rh * rh)) -
        (0.0000000000481975 * (t * t * t * rh * rh * rh)));
    return index = (index - 32.0) * (5.0 / 9.0);
}
void HeatIndexDisplay::update()
{
    auto wd = dynamic_cast<WeatherData*>(m_weatherData);
    if(wd)
    {
        m_temperature = wd->getTemperature();
        m_humidity = wd->getHumidity();
        m_heatIndex = computeHeatIndex(m_temperature, m_humidity);
    }
    display();
}
void HeatIndexDisplay::display() const
{
    std::cout << "Feels like: " << m_heatIndex << "C\n";
}