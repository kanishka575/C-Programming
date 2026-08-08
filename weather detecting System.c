#include <stdio.h>


void detectWeather(float temperature, float humidity, float windSpeed)
{
    printf("\n----- WEATHER REPORT -----\n");

    printf("Temperature : %.2f C\n", temperature);
    printf("Humidity    : %.2f %%\n", humidity);
    printf("Wind Speed  : %.2f km/h\n", windSpeed);

    if (temperature >= 35 && humidity >= 70)
    {
        printf("Weather     : Very Hot and Humid\n");
    }
    else if (temperature >= 30 && humidity < 70)
    {
        printf("Weather     : Hot and Dry\n");
    }
    else if (temperature >= 20 && temperature < 30 && humidity >= 40)
    {
        printf("Weather     : Pleasant\n");
    }
    else if (temperature < 20 && humidity >= 70)
    {
        printf("Weather     : Cold and Humid\n");
    }
    else if (temperature < 20)
    {
        printf("Weather     : Cold\n");
    }
    else
    {
        printf("Weather     : Normal\n");
    }

    if (windSpeed >= 50)
    {
        printf("Wind Alert  : Strong Wind!\n");
    }
    else if (windSpeed >= 20)
    {
        printf("Wind Alert  : Moderate Wind\n");
    }
    else
    {
        printf("Wind Alert  : Normal Wind\n");
    }
}

int main()
{
    float temperature;
    float humidity;
    float windSpeed;

    printf("===== WEATHER DETECTING SYSTEM =====\n");

    printf("Enter temperature (C): ");
    scanf("%f", &temperature);

    printf("Enter humidity (%%): ");
    scanf("%f", &humidity);

    printf("Enter wind speed (km/h): ");
    scanf("%f", &windSpeed);

    detectWeather(temperature, humidity, windSpeed);

    return 0;
}