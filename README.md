# Example PlatformIO Project for esp8266 & dht22
This is an example PlatformIO project to show how to use the **arduplot**, a PlatformIO plotting community filter (https://github.com/yhur/arduplot.git). 
<p>This tools is the equivalent to the Arduino IDE's serial plotter for the PlatformIO</p>

## Running it as part of PlatformIO monitor filter ##
1. Install the arduplot first<pre>pip install arduplot</pre>
2. copy ~/.platformio/penv/lib/python3.9/site-packages/arduplot/filter_plotter.py to either<pre>
&lt;Project&gt;/monitor</pre> for every project, or<pre>
~/.platformio/platform/espressif8266/monitor (or ~/.platformio/platform/espressif32/monitor for esp32)
</pre>Or you can just set the environment variable as below and run this without copying.<pre>
export PLATFORMIO_MONITOR_DIR=${HOME}/.platformio/penv/lib/python3.9/site-packages/arduplot/</pre>
3. With the above steps done, run <pre>pio device monitor -f plotter</pre>And you will get this plot.

<img width="937" alt="Screen Shot 2021-11-13 at 9 46 49 PM" src="https://user-images.githubusercontent.com/13171662/141644389-00e05586-837c-4bd9-9c73-5f61e2785ead.png">

### Optional Plot Configuration
If you want to put the legends to the plot. There is an optional configuration file where you can set the setting for the plotting for the project. 
<pre>
{
    "label": [
        "temperature",
        "humidity"
    ],
    "title": "Thermometer",
    "width": 100
}
</pre>

If you create a json file named **'plotcfg.json'** under the the PIO project directory, you will get this plot.
<img width="1012" alt="Screen Shot 2021-11-13 at 9 46 16 PM" src="https://user-images.githubusercontent.com/13171662/141644427-156367a3-94a8-4a27-822d-5ded39c12913.png">

