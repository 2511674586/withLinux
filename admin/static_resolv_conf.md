prevent `resolv.conf` from being changed, renamed or removed:

```shell
chattr +i /etc/resolv.conf
```
