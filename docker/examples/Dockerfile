FROM node:23-alpine

COPY package.json /express-api/
COPY . /express-api/

WORKDIR /express-api

RUN npm install

EXPOSE 3000

CMD ["node", "server.js"]