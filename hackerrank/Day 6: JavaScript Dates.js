

// The days of the week are: "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
function getDayName(dateString) {
    let dayName;
    // Write your code here
    let day = new Date(dateString);
    dayName = day.toLocaleDateString('en-US', { weekday: 'long' });
    return dayName;
}

