module.exports.calculate_credit = function(body) {
    var result = { months: [], total_percents: 0, total_payment: 0 }

    if(!body.sum) body.sum = 500000;
    if(!body.percent) body.percent = 20;
    if(!body.period) body.period = 120;

    console.log('WTFFFFFF ' + body.type);
    if('classic' == body.type) { // Classic
        var sum_per_month = body.sum / body.period;
        var percent_per_month = body.percent / 12;

        for(var i = 1; i <= body.period; ++i) {
            var month = {};
            month.month_number = i;
            month.body_payment = Number(sum_per_month).toFixed(2);
            month.remain = Number(body.sum - month.body_payment * i).toFixed(2);
            month.percent_payment = Number(month.remain * percent_per_month / 100).toFixed(2);
            month.total = (Number(month.percent_payment) + Number(month.body_payment)).toFixed(2);
            result.months.push(month);

            result.total_percents += Number(month.percent_payment);
            result.total_payment += Number(month.total);
        }
    } else { // Annuitet
        var ppm = body.percent / 12 / 100;
        var spm = body.sum * ((ppm * pow(1 + ppm, body.period)) / (pow(1 + ppm, body.period) - 1));
        var sum = body.sum;

        for(var i = 1; i <= body.period; ++i) {
            var month = {};
            month.period = i;
            month.month_number = i;
            month.percent_payment = Number(sum * ppm).toFixed(2);
            month.body_payment = Number(spm - month.percent_payment).toFixed(2);
            month.remain = Number(sum - month.body_payment).toFixed(2);
            sum -= month.body_payment;
            month.total = (Number(month.percent_payment) + Number(month.body_payment)).toFixed(2);
            result.months.push(month);

            result.total_percents += Number(month.percent_payment);
            result.total_payment += Number(month.total);
        }
    }

    result.total_percents = Number(result.total_percents).toFixed(2);
    result.total_payment  = Number(result.total_payment).toFixed(2);
    return result;
}
