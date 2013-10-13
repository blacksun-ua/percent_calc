
var express = require('express');
var routes = require('./routes');
var user = require('./routes/user');
var http = require('http');
var path = require('path');
var ejsLocals = require('ejs-locals');

var app = express();

var pages = require(__dirname + '/controllers/pages');

// all environments
app.set('port', process.env.PORT || 3000);
app.set('host', '192.168.0.101');
//app.set('views', __dirname + '/views/jade');
//app.set('view engine', 'jade');
app.engine('ejs', ejsLocals);
app.set('views', __dirname + '/views')
app.set('view engine', 'ejs');
app.use(express.favicon());
app.use(express.logger('dev'));
app.use(express.bodyParser());
app.use(express.methodOverride());
//app.use(express.session());
//app.use(express.cookieParser());
app.use(app.router);
app.use(express.static(path.join(__dirname, 'public')));

// development only
if ('development' == app.get('env')) {
  app.use(express.errorHandler());
}

app.use(function(req, res, next) {
    app.locals.route = req.url;
    next()
})

//app.get('/', routes.index);
//app.get('/users', user.list);
//app.get('/user/:id', user.id);

app.get('/home', pages.home);
app.get('/', function(req, res) { res.redirect('home') })
app.get('/example1', pages.example1);
app.get('/about', pages.about);
app.get('/calc', pages.calc);

app.post('/example1', pages.example1_post);
app.post('/calc', pages.calc_post);

module.exports = app;
