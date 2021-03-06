[![Build Status](https://dev.azure.com/lewissall/hpdporg/_apis/build/status/hpdporg.hpdp?branchName=master)](https://dev.azure.com/lewissall/hpdporg/_build/latest?definitionId=3&branchName=master)

# hpdp #

**hpdp**  High Performance Data Processing is a visualization and analytics framework. The core subsystems are a fast data **scraper**, which acts as a lightweight server, and the **trans**lation subsystem, which visualizes the dataset.

![](HTMLReport.gif)

The visualization subsystem is a customizable framework providing APIs that expose chart, layout, and interactivity specification.

A single user can script a disposable single-page report or set of charts with minimal effort. **hpdp** uses SVG (Scalable Vector Graphics) as the chart and shapes format.

## Implementations and Roadmap ##

**hpdp** has two implementations: a completed, workable port in Java and an incomplete x86_64 assembly version with flatassembler g (**fasmg**) and with a C interface.
* **port**: The java port may receive some small enhancements and fixes in the short term. Building svg output has some quirks with padding sections (regions) and requires manual tweaking.
* **core**: The assembly main version will ideally receive the next set of enhancements and reach completion. The **datap** and **rep** projects will provide the heavy lifting on the backend and the formatting/layout representation respectively. Since the **hpdp** port reached a usable proof-of-concept status, the remaining main assembly version requirements have been made clear.

## Features ##

**hpdp** provides:

* Area charts, data tables
* Data aggregation and sorting
* Tooltips to show expanded values
* Status and health indicators: Leverage **hpdp** views as project summary and project health dashboards.
* svg is part of the HTML standard, so **hpdp** output is very portable.

## Platforms ##

The **hpdp** port should compile or execute on most systems, including:
* Windows
* Linux
* Mac