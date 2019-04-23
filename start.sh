#!/usr/bin/env bash
cd startup && docker-compose up -d

echo "leaving startup" && cd ..

cd mysql && docker-compose up -d

echo "leaving mysql" && cd ..