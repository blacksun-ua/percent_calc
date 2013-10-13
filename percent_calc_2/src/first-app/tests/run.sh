#!/bin/sh

TESTS=$(shell find ./tests -type f -name "*.js")
mocha --require should --reporter spec $TESTS

mocha --require should --reporter html-cov $TESTS > coverage.html
#jscoverage app app-cov
