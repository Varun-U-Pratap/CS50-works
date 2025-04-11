const apiKey = "1174931df925007898d5840de39faff2";  // Replace with your OpenWeatherMap API key
const submitButton = document.getElementById("submit-button");
const cityInput = document.getElementById("city-input");
const weatherIcon = document.getElementById("weather-icon");
const cityName = document.getElementById("city-name");
const weatherDescription = document.getElementById("weather-description");
const temperature = document.getElementById("temperature");
const feelsLike = document.getElementById("feels-like");
const tempMin = document.getElementById("temp-min");
const tempMax = document.getElementById("temp-max");
const humidity = document.getElementById("humidity");
const windSpeed = document.getElementById("wind-speed");
const clouds = document.getElementById("clouds");
const visibility = document.getElementById("visibility");
const sunrise = document.getElementById("sunrise");
const sunset = document.getElementById("sunset");
const dayImage = document.getElementById("day-image");
const nightImage = document.getElementById("night-image");

submitButton.addEventListener("click", () => {
  const city = cityInput.value;

  if (city) {
    getWeather(city);
  } else {
    alert("Please enter a city name.");
  }
});

function getWeather(city) {
  const url = `https://api.openweathermap.org/data/2.5/weather?q=${city}&appid=${apiKey}&units=metric`;

  fetch(url)
    .then(response => response.json())
    .then(data => {
      if (data.cod === 200) {
        // Set weather data
        cityName.textContent = data.name;
        weatherDescription.textContent = data.weather[0].description;
        temperature.textContent = `Temperature: ${data.main.temp}°C`;
        feelsLike.textContent = `Feels Like: ${data.main.feels_like}°C`;
        tempMin.textContent = `Min Temp: ${data.main.temp_min}°C`;
        tempMax.textContent = `Max Temp: ${data.main.temp_max}°C`;
        humidity.textContent = `Humidity: ${data.main.humidity}%`;
        windSpeed.textContent = `Wind Speed: ${data.wind.speed} m/s`;
        clouds.textContent = `Clouds: ${data.clouds.all}%`;
        visibility.textContent = `Visibility: ${(data.visibility / 1000).toFixed(2)} km`;
        sunrise.textContent = `Sunrise: ${new Date(data.sys.sunrise * 1000).toLocaleTimeString()}`;
        sunset.textContent = `Sunset: ${new Date(data.sys.sunset * 1000).toLocaleTimeString()}`;

        // Determine if it's day or night (based on sunset/sunrise)
        const isDaytime = data.sys.sunrise < data.dt && data.sys.sunset > data.dt;

        // Add appropriate theme for day or night
        if (isDaytime) {
            document.body.classList.remove("dark-theme");
            document.body.classList.add("light-theme");
            weatherIcon.innerHTML = `<img src="sun.png" alt="Day weather icon">`;  // Replace with your day image link
          } else {
            document.body.classList.remove("light-theme");
            document.body.classList.add("dark-theme");
            weatherIcon.innerHTML = `<img src="moon.png" alt="Night weather icon">`;  // Replace with your night image link
        }
      } else {
        alert("City not found.");
      }
    })
    .catch(error => {
      console.error("Error fetching weather data: ", error);
      alert("Failed to fetch weather data.");
    });
}
