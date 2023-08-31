## github clone 项目 npm run serve 报错

> npm ERR! code ELIFECYCLE&#x20;
> npm ERR! errno 126&#x20;
> npm ERR! vue-element-admin\@4.4.0 dev: \`vue-cli-service serve\`
> npm ERR! Exit status 126
> npm ERR!
> npm ERR! Failed at the vue-element-admin\@4.4.0 dev script.
> npm ERR! This is probably not a problem with npm. There is likely additional logging output above.
> npm ERR! A complete log of this run can be found in:&#x20;
> npm ERR! ../.npm/\_logs/2023-08-29T08\_08\_59\_472Z-debug.log

解：可能是 mac 权限的问题

```sh
chmod 777 node_modules/.bin/vue-cli-service
```

