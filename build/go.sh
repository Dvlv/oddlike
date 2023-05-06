#!/bin/bash
cmake .. && make && cp compile_commands.json .. && cp oddlike .. && cd .. && ./oddlike
