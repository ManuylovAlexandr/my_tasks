import React, {Component} from 'react';
import {Switch, Route, BrowserRouter} from "react-router-dom";
import'./App.css';
import MainPage from "./components/MainPage/MainPage"
import RepositoryPage from "./components/SearchResult/RepositoryPage"

class App extends Component {
    render() {
        return (
            <BrowserRouter>
                <div className="App">
                    <Switch>
                        <Route path='/mainpage'
                               render={(props) => <MainPage/>}/>
                        <Route exact path='/'
                               render={(props) => <MainPage/>}/>
                        <Route path='/repository/:owner/:repos' component={RepositoryPage}/>
                    </Switch>
                </div>
            </BrowserRouter>
        );
    };
}

export default App;
