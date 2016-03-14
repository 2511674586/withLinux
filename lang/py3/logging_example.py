#!/usr/bin/python3

import logging as log
log.basicConfig(
  format='%(levelno)s %(asctime)s %(process)d %(filename)s:%(lineno)d]'
    +' @%(module)s::%(funcName)s %(message)s',
  level=log.DEBUG
)

log.debug("debug")

def main():
    log.info("info")
    log.warning("warning")
    log.error("error")
    log.critical("critical")

main()
