#!/bin/sh
protoc --proto_path=../protocol --java_out=src/main/java/ ../protocol/service.proto