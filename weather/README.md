# WEATHER
#### Video Demo:  <https://youtu.be/Nb5a7Bpig08>
#### Description: A program that provides weather forecasts based on the city name entered. it gives Temperature, feels like, minimum temperature, maximum temperature, humidity, wind speed, clouds, visibility, sunrise time and sunset time.
TODO
description:
About HTML:
        This code is for a simple weather app that allows users to check the weather of any city. Here's how it works:

        Page Structure: The HTML sets up the basic structure of the app.
        It includes:
        A title that says "Weather Forecast" at the top.
        A section where the weather information (like temperature, humidity, wind speed, etc.) will be displayed once the user enters a city.
        Weather Information: There are placeholders (empty spaces) for showing various weather details:

        The city name the user enters.
        The weather description (like sunny, cloudy, etc.).
        Temperature, feels-like temperature, minimum and maximum temperatures for the day.
        Additional information like humidity, wind speed, cloud cover, visibility, and times for sunrise and sunset.
        User Input: There is a text box where users can type the name of a city. Below that, a button is provided that says "Get Weather". When clicked, this button will trigger the app to fetch weather details for that city.

        Styling and Script: The code links to a separate CSS file for styling the page (like colors, fonts, and layout) and a JavaScript file that handles the functionality, such as fetching data from a weather API and displaying it on the page.

About Javascript :

        a.Global Variables
            These variables reference various HTML elements to dynamically update them based on the fetched weather data. Examples include:

            cityName, temperature, weatherDescription, etc., to display weather data.
            submitButton to handle user interaction (when the "Get Weather" button is clicked).b. Event Listener
        b.An event listener is attached to the submit button. When clicked:

            It retrieves the value from the city input field.
            If a city name is entered, it calls the getWeather() function.
            If no input is provided, it displays an alert prompting the user to enter a city name.
        c. The getWeather Function
            This function performs the following steps:

        API Call:

            Constructs the URL using the base API endpoint and appends the user's city input, the API key, and the unit of measurement (metric for Celsius).
            Uses the fetch() method to retrieve weather data from OpenWeatherMap.
            Response Handling:

            Converts the response to JSON format.
            Checks if the city is found (data.cod === 200).
            If found, it updates the weather information on the page.
            If not, it shows an alert indicating the city was not found.
        Update Weather Information:

            Updates the text content of various HTML elements with the fetched weather details.
            Formats the sunrise and sunset times into a user-friendly format (local time).
        Determine Day/Night Theme:

            Compares the current time (data.dt) with the sunrise (data.sys.sunrise) and sunset (data.sys.sunset) times to determine if it's daytime or nighttime.
            Changes the website's theme by toggling CSS classes (light-theme for day and dark-theme for night).
            Updates the weather-icon element with an appropriate image (e.g., sun for day, moon for night).
        Error Handling:

            Displays an alert if the API fails or the city is not found.
About CSS:
        1. Global Styles
            Font and Typography:
                Uses the monospace font for a clean, technical look, ensuring text clarity, with sans-serif as a fallback.
            Layout:
                Centers all content horizontally and vertically (text-align: center).
            Default Theme:
                Applies a light gray background (#E7E9E8) and black text for high readability.
            Responsive Design:
                Sets margin and padding to make the website adaptable to various devices.
            Smooth Transitions:
                Adds transitions to the background and text color (transition: background-color 0.5s ease, color 0.5s ease), ensuring seamless switching between light and dark themes.
        2. Theme-Specific Styles
            Light Theme:
                Reinforces the light theme with a soft gray background and black text, maintaining the default look.
            Dark Theme:
                Applies a darker background (#444444) and white text for better readability in low-light conditions.
                Ensures the website is visually appealing and functional for users browsing during nighttime.
Project By:
Varun U Pratap
Banglore, India
