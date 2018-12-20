# HPDP #

**HPDP**  High Performance Data Processing is a visualization and analytics framework. The core subsystems are a fast data scraper, which acts as a lightweight server, and the translation subsystem, which visualizes the dataset.

The visualization subsystem is a customizable framework providing APIs that expose chart, layout, and interactivity specification.

The data scraper can be controlled via the network and can also receive dataset updates. Updated datasets provides the option for **HPDP** systems to behave as real-time dashboards.

The **HPDP** tools allow top to bottom visualization and dynamic analytic scripting as well. A single user can therefore script a disposable single-page report or set of charts with minimal effort. **HPDP** uses SVG (Scalable Vector Graphics) as the chart and shapes format.

## Implementations ##

The **HPDP** source is written in x86_64 ASM, using flatassembler g (fasmg) with a C/C++ API. A port is also written in Java. APIs are subject to change but are planned to include a network and scripting interface.

## Features ##

Along with default charting and metric capabilities, **HPDP** will provide:

* Hierarchically-organized datasets: View data broken down by different nesting levels.
* Status and health indicators: Leverage **HPDP** views as project summary and project health dashboards.
* Advanced stochastic analytical capabilities: Plot standard deviations, frequency domain plots, trend prediction charts. 
* Exportable results and plugins: Export views as images, PDFs, and div panels.

## Platforms ##

**HPDP** should compile or execute on most systems. With minor tweaks to the Java, this is certainly possible and systems include:

* Windows
* Linux
* Mac