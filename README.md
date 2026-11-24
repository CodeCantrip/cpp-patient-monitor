# C++ Patient Monitoring and Data Analysis System

## Overview

A C++ project designed to simulate a bedside patient monitor, record physiological data, and analyze recorded monitoring sessions using Python.

Inspired by my professional background in respiratory therapy, this project focuses on applying software engineering principles to continuous data generation, configurable alarm systems, data persistence, concurrent processing, and data analysis.

I am actively learning C++ throughout development, building upon my existing programming knowledge while strengthening my understanding of software architecture, object-oriented design, and concurrent programming.

## Current Features

- Randomized heart-rate and SpO₂ generation
- Configurable high and low alarm thresholds
- Critical alarm detection
- Alarm threshold validation and input constraints
- Simulated signal detection and signal quality
- Monitor power-state management
- Continuous monitoring with timed updates
- Modular class organization using individual header files
- Dedicated CSV data logging class
- Console-based output

## Planned Features

### Data Recording
- [ ] Implement CSV data logging class
- [ ] Integrate data logging into the monitoring loop
- [ ] Record timestamps and signal quality
- [ ] Implement independent recording controls
- [ ] Support configurable recording sessions

### Simulation and Concurrent Processing
- [ ] Develop realistic, gradual physiological changes
- [ ] Simulate signal artifacts and interruptions
- [ ] Implement multithreading
- [ ] Implement thread synchronization
- [ ] Separate data generation, alarm evaluation, and recording processes

### Python Data Analysis
- [ ] Import and process recorded CSV data
- [ ] Filter unreliable readings based on signal quality
- [ ] Detect oxygen desaturation events
- [ ] Calculate event frequency and duration
- [ ] Calculate minimum, maximum, and average values
- [ ] Calculate time spent below configurable thresholds
- [ ] Generate data visualizations
- [ ] Generate monitoring session reports

### User Interface
- [ ] Develop a graphical monitoring interface
- [ ] Display real-time physiological readings
- [ ] Provide configurable alarm and recording controls
- [ ] Display historical data and analysis results

### Software Quality
- [ ] Implement automated testing
- [ ] Improve error handling
- [ ] Document architectural decisions

## Technologies

### Currently Used
- C++
- C++ Standard Library
- CSV file handling
- Microsoft Visual Studio
- Git and GitHub

### Planned
- Python
- Python data analysis and visualization libraries
- Qt

## Engineering Objectives

- Separation of concerns
- Object-oriented design
- Modular and maintainable architecture
- Concurrent programming and thread safety
- Data persistence and processing
- Input validation and error handling
- Cross-language integration
- Automated testing

## Project Status

**In Active Development**

The foundational monitoring and alarm logic has been implemented. Current development focuses on integrating data persistence before expanding into concurrent processing, realistic simulations, and Python-based analytics.

This project is being developed incrementally as I continue expanding my technical knowledge and practical software engineering experience.

## Disclaimer

This project is an educational software simulation only. It is not intended for clinical use, actual patient monitoring, diagnosis, or medical decision-making.
