import calendar

month, date, year = map(int, raw_input().split())

arr = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday', 'Sunday']

print(arr[calendar.weekday(year, month, date)].upper())