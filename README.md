# City Selector
Welcome to the City Selector! This tool uses C++, Qt, and a csv file of about 47 thousand cities to help you select a 
city that adequately suits your preferences. This database was compiled by simplemaps, in coordination with the NGIA, 
US Geological Survey, and NASA. A copy of this data set may be found [here](https://simplemaps.com/data/world-cities). 
Simply input a country of choice and then an integer of 1-5 to represent 
your preferred city size and climate. The values are scaled to reflect the data in 20% benchmarks. An integer of 5 will 
represent the top 20% most populous cities and the coordinates furthest from the equator, between latitudinal coordinates 
60 and 75. The breakdown of what each integer input represents is shown in the table below.

| Input <br/>(integer) | Population<br/>(percentile) | Weather <br/>(absolute latitude) |
|-----------------------------|-----------------------------|----------------------------------|
| 1                           | 0-20                        | 1-15                             |
| 2                           | 21-40                       | 16-30                            |
| 3                           | 41-60                       | 31-45                            |
| 4                           | 61-80                       | 46-60                            |
| 5                           | 81-100                      | 61-75                            |

Note that weather is approximated as the absolute value of the latitudinal coordinate. Thus, regions near the North or 
South Pole are evaluated to be similarly cold and values in the tropics are estimated to be equally hot.

## How to Run On Your Machine

This project was created in C++ on the Qt framework, as such, the recommended software to use for viewing and running 
the project is the Qt IDE. 

### Step 1: Install Qt

Qt is a development framework with user-friendly libraries and a built-in IDE. After installation and a brief period of
familiarization, the framework allows quick development with elegant outcomes. The package is available for
download [here](https://www.qt.io/download-dev)!

### Step 2: Download Source and Header Files

After installing Qt, start a new "Application" project. The project will create a CMake file with all the necessary
libraries included and correctly linked. Then, download the source and header files saved in the repo folder "src" and
move them into the folder where your new Qt project is saved. Files will appear in the project directory and make be run
from the IDE.

### Step 3: Enjoy!

You are the proud new owner and operator of the newest City Selector franchise! 