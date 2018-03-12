#!/bin/bash
echo "\n-------------------remove *.pyc----------"
find . -name "*.pyc"|xargs rm
echo "\n-------------------remove *.py~----------"
find . -name "*.py~"|xargs rm
