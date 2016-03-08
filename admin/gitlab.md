Gitlab notes
===

1. download .deb file from gitlab.com  
2. dpkg -i gitlab-ce_*.deb  
3. vim /etc/gitlab/gitlab.rb  
4. gitlab-ctl reconfigure  
5. gitlab-ctl restart
6. start your browser
7. login with the default account `root`, password `5iveL!fe`.`

### Troubleshot

#### freeze on xx\_redis\_sleep
Start an instance of /opt/gitlab/embedded/bin/runsvdir-start, then
reconfigure. or start service gitlab-runsvdir.service

#### How to disable "sign up" for accounts ?
For gitlab 8.3.2, login with admin account, then find related settings
in admin area.

#### Reference
1. Gitlab official doc
2. archwiki gitlab
