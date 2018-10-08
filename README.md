# HPDP #

**HPDP**  High Performance Data Processing is a visualization and analytics framework. The core subsystems are a fast data scraper, which acts as a lightweight server, and the translation subsystem, which visualizes the dataset.

The visualization subsystem is a customizable framework providing APIs that expose chart, layout, and interactivity specification.

The data scraper can be controlled via the network and can also receive dataset updates. Updated datasets provides the option for **HPDP** systems to behave as real-time dashboards.

The **HPDP** tools allow top to bottom visualization and dynamic analytic scripting as well. A single user can therefore script a disposable single-page report or set of charts with minimal effort.

## Implementations ##

The **HPDP** source is written in ASM, using flatassembler g (fasmg). APIs are subject to change but are planned to include asm, C/C++, Java, along with a network and scripting interface.

## Features ##

Along with default charting and metric capabilities, **HPDP** will provide:

* Hierarchically-organized datasets: View data broken down by different nesting levels.
* Status and health indicators: Leverage **HPDP** views as project summary and project health dashboards.
* Advanced stochastic analytical capabilities: Plot standard deviations, frequency domain plots, trend prediction charts. 
* Exportable results and plugins: Export views as images, PDFs, and div panels.

## Platforms ##

**HPDP** should compile or execute on most systems, including:

* Windows
* Linux
* Mac