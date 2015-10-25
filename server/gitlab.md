Gitlab notes
===

1. download .deb file from gitlab.com  
2. dpkg -i gitlab-ce_*.deb  
3. vim /etc/gitlab/gitlab.rb  
4. gitlab-ctl reconfigure  
5. gitlab-ctl restart

### Troubleshot

#### freeze on xx\_redis\_sleep
Start an instance of /opt/gitlab/embedded/bin/runsvdir-start, then
reconfigure. or start service gitlab-runsvdir.service

#### Reference
1. Gitlab official doc
2. archwiki gitlab
