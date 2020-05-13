#! /bin/env bash 

read -p "input your git add filename:" filename

git add $(filename)
git commit -a -m "$(filename)"
git push

expect{
 "Username for 'https://github.com':"{send "wolfGuidao\r",exp_continue}
 "Password for 'https://wolfGuidao@github.com':"{send "lttfyt137126\r"}
}
